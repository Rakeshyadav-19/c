<!-- session_start Function -->
<?php
// start a session
session_start();
//Get a Session Id
echo session_id();
?>

<!--  initialize session variables. -->
<?php
// start a session
session_start();
  
// initialize session variables
$_SESSION['logged_in_user_id'] = '7';
$_SESSION['logged_in_user_name'] = 'Thala';
  
// access session variables
echo$_SESSION['logged_in_user_id'];
echo$_SESSION['logged_in_user_name'];
?>

<!-- Modify and Delete Session Variables -->
<?php
session_start();
  
if(!isset($_SESSION['count']))
{
  $_SESSION['count'] = 1;
}
else
{
  ++$_SESSION['count'];
}
  
echo$_SESSION['count'];
?>

<!-- delete a session variable -->
<?php
// start a session
session_start();
  
// initialize a session variable
$_SESSION['logged_in_user_id'] = '1';
  
// unset a session variable
unset($_SESSION['logged_in_user_id']);
?>





<!-- File 1 -->
<?php
session_start();   
?>
<html>
    <body>
        <h2>PHP Session</h2>
        <?php
        $_SESSION["Roll_Number"] = "7000";
        $_SESSION["Name"] = "Thala"; 
        echo "Thala information are set successfully.<br/>";
        ?>
        <!-- <a href="Experiment10_2.php">Visit next page</a>  -->
    </body>
</html> 

<!-- File 2 -->
<?php  
session_start();  
?>  
<html>
    <body>
        <h2>PHP Session</h2>
        <?php
        echo 'The Name of the student is :' . $_SESSION["Name"] . '<br>';  
        echo 'The Roll number of the student is :' . $_SESSION["Roll_Number"] . '<br>'; 
        print_r($_SESSION);
        ?>   
    </body>  
</html>  


