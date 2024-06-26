<?php
$con = new mysqli('localhost', 'root', 'cloud123', 'DBMS');
$sql = "CALL Get_Data();";
$res = mysqli_query($con, $sql);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Customer Details</title>
</head>
<body>
    <h2>Customer Details</h2>
    <table>
        <thead>
            <tr>
                <th>Customer ID</th>
                <th>CustomerName</th>
                <th>ContactName</th>
                <th>Country</th>
            </tr>
        </thead>
        <tbody>
            <?php while ($row = mysqli_fetch_assoc($res)): ?>
                <tr>
                    <td><?php echo $row['CustomerID']; ?></td>
                    <td><?php echo $row['CustomerName']; ?></td>
                    <td><?php echo $row['ContactName']; ?></td>
                    <td><?php echo $row['Country']; ?></td>
                </tr>
            <?php endwhile; ?>
        </tbody>
    </table>
</body>
</html>

<?php
// Close the connection
mysqli_close($con);
?>
