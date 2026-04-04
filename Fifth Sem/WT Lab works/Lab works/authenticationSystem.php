<?php
session_start();
$conn = new mysqli("localhost", "root", "", "auth_db");
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Logout Logic
if (isset($_GET['logout'])) {
    session_destroy();
    setcookie("user", "", time() - 3600, "/");
    header("Location: index.php");
    exit();
}

// Auto Login via Cookie
if (!isset($_SESSION['user']) && isset($_COOKIE['user'])) {
    $_SESSION['user'] = $_COOKIE['user'];
}

// Registration Logic
if (isset($_POST['register'])) {
    $username = trim($_POST['username']);
    $email = trim($_POST['email']);
    $password = $_POST['password'];
    
    if (empty($username) || empty($email) || empty($password)) {
        $error = "All fields are required!";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $error = "Invalid email format!";
    } else {
        $hashed = password_hash($password, PASSWORD_DEFAULT);
        $stmt = $conn->prepare("INSERT INTO users (username, email, password) VALUES (?, ?, ?)");
        $stmt->bind_param("sss", $username, $email, $hashed);
        if ($stmt->execute()) {
            $success = "Registered successfully! Please login.";
        } else {
            $error = "Username or Email already exists!";
        }
    }
}

// Login Logic
if (isset($_POST['login'])) {
    $username = $_POST['username'];
    $password = $_POST['password'];
    
    $stmt = $conn->prepare("SELECT * FROM users WHERE username=?");
    $stmt->bind_param("s", $username);
    $stmt->execute();
    $result = $stmt->get_result();
    $user = $result->fetch_assoc();
    
    if ($user && password_verify($password, $user['password'])) {
        $_SESSION['user'] = $user['username'];
        if (isset($_POST['remember'])) {
            setcookie("user", $user['username'], time() + (86400 * 7), "/");
        }
        header("Location: index.php");
        exit();
    } else {
        $error = "Invalid username or password!";
    }
}

$loggedIn = isset($_SESSION['user']);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Secure Login Portal</title>
    <style>
        body {
            font-family: 'Verdana', sans-serif;
            background: #dfe6e9;
            margin: 0;
            padding: 40px 20px;
            display: flex;
            flex-direction: column;
            align-items: center;
        }
        h2 { color: #2d3436; }
        .msg { color: #d63031; background: #fab1a0; padding: 10px; border-radius: 5px; margin-bottom: 20px; }
        .success { color: #00b894; background: #55efc4; padding: 10px; border-radius: 5px; margin-bottom: 20px; }
        
        .auth-container {
            display: flex;
            gap: 20px;
            flex-wrap: wrap;
            justify-content: center;
            width: 100%;
            max-width: 800px;
        }
        .box {
            background: white;
            border: 1px solid #b2bec3;
            padding: 25px;
            width: 300px;
            border-radius: 10px;
            box-shadow: 0 4px 6px rgba(0,0,0,0.1);
        }
        .box h3 { margin-top: 0; color: #0984e3; border-bottom: 2px solid #0984e3; padding-bottom: 10px; }
        input {
            width: 90%;
            margin: 10px 0;
            padding: 10px;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        button {
            width: 100%;
            padding: 10px;
            background: #0984e3;
            color: white;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            font-size: 16px;
            margin-top: 10px;
        }
        button:hover { background: #74b9ff; }
        .welcome-box {
            background: white;
            padding: 40px;
            text-align: center;
            border-radius: 10px;
            box-shadow: 0 4px 15px rgba(0,0,0,0.2);
            border-top: 5px solid #00b894;
        }
        .logout-btn {
            background: #d63031;
            display: inline-block;
            padding: 10px 20px;
            color: white;
            text-decoration: none;
            border-radius: 5px;
            margin-top: 20px;
        }
        .footer { margin-top: 50px; font-size: 12px; color: #636e72; }
    </style>
</head>
<body>
    <h2>Secure Authentication System</h2>
    
    <?php if (isset($error)) echo "<div class='msg'>$error</div>"; ?>
    <?php if (isset($success)) echo "<div class='success'>$success</div>"; ?>
    
    <?php if ($loggedIn) : ?>
        <div class="welcome-box">
            <h1>Welcome, <?php echo htmlspecialchars($_SESSION['user']); ?>! 🎉</h1>
            <p>You have successfully logged in.</p>
            <a href="?logout=1" class="logout-btn">Logout Securely</a>
        </div>
    <?php else : ?>
        <div class="auth-container">
            <!-- Registration Form -->
            <div class="box">
                <h3>Create Account</h3>
                <form method="POST">
                    <input type="text" name="username" placeholder="Choose Username" required>
                    <input type="email" name="email" placeholder="Email Address" required>
                    <input type="password" name="password" placeholder="Password" required>
                    <button type="submit" name="register">Register</button>
                </form>
            </div>
            
            <!-- Login Form -->
            <div class="box">
                <h3>Member Login</h3>
                <form method="POST">
                    <input type="text" name="username" placeholder="Username" required>
                    <input type="password" name="password" placeholder="Password" required>
                    <label style="font-size: 14px;">
                        <input type="checkbox" name="remember" style="width: auto;"> Remember Me
                    </label>
                    <button type="submit" name="login">Login</button>
                </form>
            </div>
        </div>
    <?php endif; ?>
    
    <div class="footer">
        Security Module &copy; 2025 | Designed by Vivek Paudel
    </div>
</body>
</html>