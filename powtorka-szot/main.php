<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

    <!-- Formularze -->
    <form method="POST" action="<?php echo $_SERVER['PHP_SELF']; ?>">
        num: <input type="number" name="num">
        <input type="submit">
    </form>

    <?php
        /* Formularze */
        if($_SERVER['REQUEST_METHOD'] == "POST")
        {
            $number = $_POST['num'];
            if(empty($number))
            {
                die("Number is empty");
            }
            else
            {
                echo $number."<br><br>";
            }
        }

        /* Połączenie z bazą danych MySQL */
        $conn = new mysqli("localhost", "root", "", "sklep");
        if($conn->connect_error)
        {
            die("Connection failed: ".$conn->connect_error);
        }

        $sql = "SELECT * FROM towary";
        $query_result = $conn->query($sql);

        if($query_result->num_rows > 0)
        {
            while($row = $query_result->fetch_assoc())
            {
                echo "ID: ".$row['id']."<br>";
                echo "Nazwa: ".$row['nazwa']."<br>";
                echo "Cena: ".$row['cena']."<br>";
                echo "Promocja: ".$row['promocja']."<br>";
                echo "ID_dostawcy: ".$row['idDostawcy']."<br><br><br>";
            }
        }

        // Baza danych, arkusz1.sql 
    ?>
</body>
</html>


