<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Restauracja Wszystkie Smaki</title>
    <link rel="stylesheet" href="styl_1.css">
</head>
<body>
    <main>
        <header>
            <h1>Witamy w restauracji "Wszystkie Smaki"</h1>
        </header>
        <section class="container">
            <section class="inner-container box">
                <section class="panel" id="left">
                    <img src="menu.jpg" alt="Nasze dania">
                </section>
                <section class="panel" id="right">
                    <h4>U nas dobrze zjesz!</h4>
                    <ol>
                        <li>Obiady od 40 zł</li>
                        <li> Przekąski od 10 zł</li>
                        <li> Kolacje od 20 zł</li>
                    </ol>
                </section>
            </section>
            <section class="box" id="down">
                <h2>Zarezerwuj stolik online</h2>
                <form action="rezerwacja.php" method="POST">
                    Data (format rrrr-mm-dd): <br>
                    <input type="date" name="data"><br>
                    Ile osób?:<br>
                    <input type="number" name="osoby"><br>
                    Twój numer telefonu:<br>
                    <input type="number" name="telefon"><br>
                    <input type="checkbox" name="zgoda">Zgadzam się na przetwarzanie moich danych osobowych
                    <br><button type="reset">WYCZYŚĆ</button>
                    <button type="submit">REZERWUJ</button>
                </form>
            </section>
        </section>
        <footer>
            Prace wykonał: 1234567890
        </footer>
    </main>
</body>
</html>