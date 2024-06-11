<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Collect form data
    $name = htmlspecialchars(trim($_POST['name']));
    $email = htmlspecialchars(trim($_POST['email']));
    $message = htmlspecialchars(trim($_POST['message']));

    // Validate data (optional, but recommended)
    if (!empty($name) && !empty($email) && !empty($message)) {
        // Here you could save the data to a database, send an email, etc.
        
        // For demonstration, just echo the received data
        echo "<h2>Received Input</h2>";
        echo "Name: $name<br>";
        echo "Email: $email<br>";
        echo "Message: $message<br>";
    } else {
        echo "All fields are required!";
    }
} else {
    // In case someone tries to access process.php directly
    echo "Form not submitted correctly.";
}
?>
