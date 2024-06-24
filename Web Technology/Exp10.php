<!-- session_start Function -->
<?php
// start a session
session_start();
//Get a Session Id
echo session_id();
?>

<?php
//session_id(0tjcc2fg5m30mhjhm3hrcdte5e);
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

