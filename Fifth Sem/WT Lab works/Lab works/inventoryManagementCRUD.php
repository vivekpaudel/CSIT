<?php
// Database Connection
$conn = new mysqli("localhost", "root", "", "inventory_db");
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// ADD Product
if (isset($_POST['add'])) {
    $name = $_POST['name'];
    $price = $_POST['price'];
    $quantity = $_POST['quantity'];
    $stmt = $conn->prepare("INSERT INTO products (product_name, price, quantity) VALUES (?, ?, ?)");
    $stmt->bind_param("sdi", $name, $price, $quantity);
    $stmt->execute();
    header("Location: index.php");
}

// DELETE Product
if (isset($_GET['delete'])) {
    $id = $_GET['delete'];
    $conn->query("DELETE FROM products WHERE id=$id");
    header("Location: index.php");
}

// EDIT Logic
$editData = null;
if (isset($_GET['edit'])) {
    $id = $_GET['edit'];
    $result = $conn->query("SELECT * FROM products WHERE id=$id");
    $editData = $result->fetch_assoc();
}

// UPDATE Product
if (isset($_POST['update'])) {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $price = $_POST['price'];
    $quantity = $_POST['quantity'];
    $stmt = $conn->prepare("UPDATE products SET product_name=?, price=?, quantity=? WHERE id=?");
    $stmt->bind_param("sdii", $name, $price, $quantity, $id);
    $stmt->execute();
    header("Location: index.php");
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Inventory Dashboard</title>
    <style>
        body { font-family: 'Arial', sans-serif; background-color: #f4f6f9; margin: 0; padding: 20px; }
        .wrapper { max-width: 900px; margin: 0 auto; }
        h2 { color: #2c3e50; border-bottom: 2px solid #3498db; padding-bottom: 10px; }
        
        /* Form Styling */
        .form-box {
            background: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 5px rgba(0,0,0,0.1);
            margin-bottom: 30px;
            border-left: 5px solid #3498db;
        }
        input { padding: 10px; margin: 5px 0; border: 1px solid #ddd; border-radius: 4px; width: 200px; }
        button {
            padding: 10px 20px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-weight: bold;
            color: white;
        }
        .btn-add { background-color: #27ae60; }
        .btn-update { background-color: #f39c12; }
        .btn-cancel { background-color: #95a5a6; text-decoration: none; padding: 10px 20px; color: white; display: inline-block; }
        
        /* Table Styling */
        table { width: 100%; border-collapse: collapse; background: white; box-shadow: 0 2px 5px rgba(0,0,0,0.1); border-radius: 8px; overflow: hidden; }
        th, td { padding: 15px; text-align: left; border-bottom: 1px solid #eee; }
        th { background-color: #2c3e50; color: white; text-transform: uppercase; font-size: 14px; }
        tr:hover { background-color: #f1f1f1; }
        
        /* Action Links */
        .action-link { text-decoration: none; padding: 5px 10px; border-radius: 4px; color: white; font-size: 12px; margin-right: 5px; }
        .edit-link { background-color: #3498db; }
        .delete-link { background-color: #e74c3c; }
        
        .footer { text-align: center; margin-top: 50px; color: #7f8c8d; font-size: 12px; }
    </style>
</head>
<body>
    <div class="wrapper">
        <h2><?php echo $editData ? "Update Product Record" : "Add New Product"; ?></h2>
        
        <div class="form-box">
            <form method="POST">
                <input type="hidden" name="id" value="<?php echo $editData['id'] ?? ''; ?>">
                <label>Product Name:</label><br>
                <input type="text" name="name" value="<?php echo $editData['product_name'] ?? ''; ?>" required><br>
                <label>Price:</label><br>
                <input type="number" step="0.01" name="price" value="<?php echo $editData['price'] ?? ''; ?>" required><br>
                <label>Quantity:</label><br>
                <input type="number" name="quantity" value="<?php echo $editData['quantity'] ?? ''; ?>" required><br><br>
                
                <?php if ($editData) : ?>
                    <button type="submit" name="update" class="btn-update">Update Record</button>
                    <a href="index.php" class="btn-cancel">Cancel</a>
                <?php else : ?>
                    <button type="submit" name="add" class="btn-add">Add Product</button>
                <?php endif; ?>
            </form>
        </div>

        <h2>Product Inventory List</h2>
        <table>
            <tr>
                <th>ID</th>
                <th>Product Name</th>
                <th>Price (NPR)</th>
                <th>Quantity</th>
                <th>Actions</th>
            </tr>
            <?php
            $result = $conn->query("SELECT * FROM products");
            while ($row = $result->fetch_assoc()) {
                echo "<tr>
                    <td>{$row['id']}</td>
                    <td>{$row['product_name']}</td>
                    <td>Rs. {$row['price']}</td>
                    <td>{$row['quantity']}</td>
                    <td>
                        <a href='?edit={$row['id']}' class='action-link edit-link'>Edit</a>
                        <a href='?delete={$row['id']}' class='action-link delete-link' onclick=\"return confirm('Are you sure you want to delete this item?')\">Delete</a>
                    </td>
                </tr>";
            }
            ?>
        </table>
    </div>
    <div class="footer">
        Inventory System &copy; 2025 | Vivek Paudel
    </div>
</body>
</html>