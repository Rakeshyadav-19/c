<!-- session_start Function -->
<?php
// start a session
session_start();
  // manipulate session variables
?>


<!-- Automatically Start a Session -->
session.auto_start = 1

<!--  Get a Session Id -->
<?php
session_start();
echosession_id();
?>

<?php
session_id(YOUR_SESSION_ID);
session_start();
?>

<!--  initialize session variables. -->

<?php
// start a session
session_start();
  
// initialize session variables
$_SESSION['logged_in_user_id'] = '1';
$_SESSION['logged_in_user_name'] = 'Tutsplus';
  
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

