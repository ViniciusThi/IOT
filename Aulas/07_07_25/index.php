<?php require_once 'conexao.php'; ?>
<!DOCTYPE html>
<html lang="pt-br">
    <head>
        <meta charset="UTF-8">
        <title>Painel de sensores</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href="style.css">
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css">
        <script src="https://cdnjs.cloudflare.com/ajax/libs/three.js/r128/three.min.js"></script>
        <script src="https://cdn.jsdelivr.net/npm/three@0.132.2/examples/js/controls/OrbitControls.js"></script>
    </head>
    <body>
        <div class="container">
            <h1>Painel de Monitoramento</h1>
            
            <div id="dashboard3D"></div>
            
            <div class="data-container">
                <div class="card temperatura">
                    <div class="card-icon"><i class="fas fa-temperature-high"></i></div>
                    <div class="card-value" id="temperatura-atual">--°C</div>
                    <div class="card-label">Temperatura</div>
                </div>
                
                <div class="card umidade">
                    <div class="card-icon"><i class="fas fa-tint"></i></div>
                    <div class="card-value" id="umidade-atual">--%</div>
                    <div class="card-label">Umidade</div>
                </div>
                
                <div class="card luminosidade">
                    <div class="card-icon"><i class="far fa-lightbulb"></i></div>
                    <div class="card-value" id="luminosidade-atual">-- lux</div>
                    <div class="card-label">Luminosidade</div>
                </div>
            </div>

            <table>
                <thead>
                    <tr>
                        <th><i class="far fa-clock"></i> Data/Hora</th>
                        <th><i class="fas fa-temperature-high"></i> Temperatura (°C)</th>
                        <th><i class="fas fa-tint"></i> Umidade (%)</th>
                        <th><i class="far fa-lightbulb"></i> Luminosidade (lux)</th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                        $sql = "SELECT * FROM sensores ORDER BY data_hora DESC LIMIT 20";
                        $res = $conn->query($sql);
                        
                        $dados_json = array();

                        if ($res->num_rows > 0) {
                            while($linha = $res->fetch_assoc()) {
                                echo "<tr>";
                                    echo "<td>" . $linha['data_hora'] . "</td>";
                                    
                                    $temp_class = ($linha['temperatura'] > 30) ? 'valor-critico' : 'valor-normal';
                                    echo "<td class='" . $temp_class . "'>" . $linha['temperatura'] . "</td>";
                                    
                                    $umidade_class = ($linha['umidade'] < 30) ? 'valor-critico' : 'valor-normal';
                                    echo "<td class='" . $umidade_class . "'>" . $linha['umidade'] . "</td>";
                                    
                                    echo "<td>" . $linha['luminosidade'] . "</td>";
                                echo "</tr>";
                                
                                $dados_json[] = array(
                                    'data_hora' => $linha['data_hora'],
                                    'temperatura' => floatval($linha['temperatura']),
                                    'umidade' => floatval($linha['umidade']),
                                    'luminosidade' => intval($linha['luminosidade'])
                                );
                            }
                        } else {
                            echo "<tr><td colspan='4'>Nenhum dado disponível</td></tr>";
                        }
                        $conn->close();
                    ?>
                </tbody>
            </table>
        </div>

        <script>
            const dadosSensores = <?php echo json_encode(array_reverse($dados_json)); ?>;
        </script>
        <script src="script.js"></script>
    </body>
</html>