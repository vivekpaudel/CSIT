<?php
//Function to calculate division based on percentage
function calculateDivision($percentage) {
    if ($percentage >= 80) {
        return "Distinction";
    } elseif ($percentage >= 60) {
        return "First Division";
    } elseif ($percentage >= 50) {
        return "Second Division";
    } elseif ($percentage >= 40) {
        return "Third Division";
    } else {
        return "Fail";
    }
}

$reportCard = null;

// Process the form when submitted
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['marks'])) {
    $marks = $_POST['marks']; // Stores subject marks in an associative array
    $totalMarks = 0;
    $subjectCount = count($marks);
    
    // Use foreach control structure to iterate through the array
    foreach ($marks as $subject => $score) {
        $totalMarks += (float)$score;
    }
    
    $maxPossible = $subjectCount * 100;
    $percentage = ($totalMarks / $maxPossible) * 100;
    $division = calculateDivision($percentage);
    
    $reportCard = [
        "total" => $totalMarks,
        "percent" => number_format($percentage, 2),
        "division" => $division
    ];
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Academic Result System</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: linear-gradient(135deg, #e0f7fa 0%, #ffffff 100%);
            padding: 40px 20px;
            margin: 0;
            color: #333;
        }
        .container {
            max-width: 500px;
            background: white;
            padding: 30px;
            border-radius: 12px;
            box-shadow: 0 10px 25px rgba(0,0,0,0.1);
            margin: 0 auto;
            border-top: 5px solid #009688;
        }
        h2 {
            text-align: center;
            color: #00796b;
            margin-bottom: 25px;
        }
        label {
            font-weight: 600;
            display: block;
            margin-top: 15px;
            color: #555;
        }
        input {
            width: 100%;
            padding: 12px;
            margin-top: 5px;
            border: 1px solid #ddd;
            border-radius: 6px;
            box-sizing: border-box;
            transition: border 0.3s;
        }
        input:focus {
            border-color: #009688;
            outline: none;
        }
        button {
            background: #009688;
            color: white;
            padding: 15px;
            border: none;
            cursor: pointer;
            width: 100%;
            margin-top: 25px;
            border-radius: 6px;
            font-size: 16px;
            font-weight: bold;
            transition: background 0.3s;
        }
        button:hover {
            background: #00796b;
        }
        .result {
            margin-top: 30px;
            padding: 20px;
            border-radius: 8px;
            background: #e0f2f1;
            border-left: 5px solid #009688;
            animation: fadeIn 0.5s;
        }
        .result h3 {
            margin-top: 0;
            color: #00796b;
        }
        .footer {
            text-align: center;
            margin-top: 40px;
            font-size: 12px;
            color: #888;
        }
        @keyframes fadeIn {
            from { opacity: 0; transform: translateY(10px); }
            to { opacity: 1; transform: translateY(0); }
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Student Grade Calculator</h2>
        <form method="POST">
            <label>Mathematics</label>
            <input type="number" name="marks[Math]" required min="0" max="100" placeholder="Enter marks">
            
            <label>Science</label>
            <input type="number" name="marks[Science]" required min="0" max="100" placeholder="Enter marks">
            
            <label>English</label>
            <input type="number" name="marks[English]" required min="0" max="100" placeholder="Enter marks">
            
            <label>Social Studies</label>
            <input type="number" name="marks[Social]" required min="0" max="100" placeholder="Enter marks">
            
            <button type="submit">Calculate Result</button>
        </form>
        
        <?php if ($reportCard) : ?>
            <div class="result">
                <h3>Academic Report</h3>
                <p><strong>Total Scored:</strong> <?= $reportCard['total'] ?> / 400</p>
                <p><strong>Percentage:</strong> <?= $reportCard['percent'] ?>%</p>
                <p><strong>Division:</strong> <?= $reportCard['division'] ?></p>
            </div>
        <?php endif; ?>
    </div>
    <div class="footer">
        &copy; 2025 Web Technology Lab | Developed by Vivek Paudel
    </div>
</body>
</html>