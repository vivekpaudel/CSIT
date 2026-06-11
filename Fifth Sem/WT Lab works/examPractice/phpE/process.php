<!DOCTYPE html>
<html>
    <link rel="stylesheet" href="style.css">
    <head><title>PHP Page</title></head>

</html>
<?php
$conn = mysqli_connect("localhost", "root", "", "exam_db");
if ($conn) {
    echo "Connection successful<br>";
}

$sql = "CREATE TABLE IF NOT EXISTS details(name VARCHAR(20),phone INT)";
mysqli_query($conn, $sql);

echo "<h1>You are in PHP<h1><br>";
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST["name"];
    $phone = $_POST["phoneNumber"];
    insertdb($name, $phone, $conn);
    display();
}

function insertdb($name, $phone, $conn)
{
    $sql = "INSERT INTO details(name,phone)VALUES ('$name','$phone')";
    mysqli_query($conn, $sql);
}

function display()
{
    $conn = mysqli_connect("localhost", "root", "", "exam_db");
    $result = mysqli_query($conn, "SELECT * from details");
    echo "<table>
    <tr>
        <th>Name</th>
        <th>Phone</th>
    </tr></table>";
    while ($row = mysqli_fetch_assoc($result)) {
        echo "
        <table>
        <tr>
            <td>" .
            $row["name"] .
            "<td>" .
            $row["phone"] .
            "</td>
            </tr>
        </table>";
    }
}

?>
