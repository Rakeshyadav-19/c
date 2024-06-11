<?php
    $x = 5;
    $y = 4;
    echo $x + $y;
?>


<?php
    $txt = "W3Schools.com";
    echo "I love " . $txt . "!";
?>

<?php
    $x = 5;
    function myTest() {
        echo "<p>Variable x inside function is: $x</p>";
    }
    myTest();
    echo "<p>Variable x outside function is: $x</p>";
?>


<?php
     $d =date("D");
if($d =="Fri")
echo"Have a nice weekend!";
else
echo"Have a nice day!";
?>

<?php
    $array =array(1,2,3,4,5);
foreach( $array as $value ){
echo"Value is $value <br/>";
}
?>

<?php
    $x=15;
    $y=5;
    if ($x > $y) {
        echo "$x is greater than $y";
    } else if ($x< $y) {
        echo "$x is less than $y";
    } else {
        echo "Both are Equal";
    }
?>

<?php
    $x=15;
    $y=10;
    $op='*';
    switch($op)
    {
        case '+':
            $z = $x + $y;
            echo "Addition is : $z";
            break;
        case '-':
            $z = $x - $y;
            echo "Subtraction is : $z";
            break;
        case '*':
            $z = $x * $y;
            echo "Multiplication is : $z";
            break;
        case '/':
            $z = $x / $y;
            echo "Division is : $z";
            break;
        case '%':
            $z = $x % $y;
            echo "Modulus is : $z";
            break;
        default:
            echo "Invalid Operator";
    }
?>

<?php
    $n = 1;
    while ($n <= 5) {
        echo "$n <br/>";
        $n++;
    }
    ?>

    <?php
    $n = 1;
    do {
        echo "$n <br/>";
        $n++;
    } while ($n <= 5);
    ?>

<?php
    for ($i = 1; $i<= 5; $i++) {
        echo "$i<br/>";
    }
?>

<?php
    for ($i = 1; $i<= 10; $i++) {
        if ($i == 5) {
            break; // terminates the current loop
        }
        echo "$i<br/>";
    }
    echo "Loop is Over !";
    ?>

<?php
    for ($i = 1; $i<= 10; $i++) {
        if ($i % 2 == 0) {
            continue; // terminates the current iteration and moves to the next
        }
        echo "$i<br/>";
    }
    echo "Loop is Over !";
    ?>


<?php
    $marks = array(60, 78, 87, 67);
    echo "Marks are: $marks[0], $marks[1], $marks[2], and $marks[3]";
    ?>

<?php
    $marks = array("WT" => 56, "FLAT" => 67, "SE" => 65, "PPL" => 78);
    echo "Marks of WT: " . $marks["WT"] . "<br/>";
    echo "Marks of FLAT: " . $marks["FLAT"] . "<br/>";
    echo "Marks of SE: " . $marks["SE"] . "<br/>";
    echo "Marks of PPL: " . $marks["PPL"] . "<br/>";
    ?>


<?php
    $students = array(
        array(501, "Kiran", 20),
        array(502, "Hari", 21),
        array(503, "Naveen", 20)
    );
    for ($i = 0; $i< 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            echo $students[$i][$j] . " ";
        }
        echo "<br/>";
    }
    ?>

