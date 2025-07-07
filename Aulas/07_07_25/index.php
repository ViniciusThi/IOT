<?php require_once 'conexao.php'; ?>
<!DOCTYPE html>
<html lang="pt-br">
    <head>
        <meta charset="UTF-8">
        <title>Painel de sensores</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href="style.css">
    </head>
    <body>

        <h1>Painel de monitoramento</h1>

        <table>
            <tr>
                <th>Data/Hora</th>
                <th>Temperatura (°C)</th>
                <th>Umidade (%)</th>
                <th>Luminosidade (lux)</th>
            </tr>

            <?php
                $sql = "SELECT * FROM sensores ORDER BY data_hora DESC LIMIT 20";
                $res = $conn->query($sql);

                while($linha = $res->fetch_assoc()){
                    echo "<tr>";
                        echo "<td>" . $linha['data_hora'] . "</td>";
                        echo "<td>" . $linha['temperatura'] . "</td>";
                        echo "<td>" . $linha['umidade'] . "</td>";
                        echo "<td>" . $linha['luminosidade'] . "</td>";
                    echo "</tr>";
                }
                $conn->close();
            ?>
        </table>
    </body>
</html>