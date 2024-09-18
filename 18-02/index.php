<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>18-02</title>
</head>
<body>
    <form method="POST" action="<?php echo $_SERVER['PHP_SELF'] ?>">
        Text: <input type="text" id="text_area" name="Ftext">
        <input type="submit" id="btn" name="btn" value="analizuj">
    </form>

    <?php
        if($_SERVER['REQUEST_METHOD'] == "POST")
        {
            // Collect data
            $text = $_POST['Ftext'];
            if(empty($text))
            {
                echo "Text area is empty";
            }

            $text_array = str_split($text);
            
            print_r(array_count_values($text_array));
        }
    ?>
</body>
</html>