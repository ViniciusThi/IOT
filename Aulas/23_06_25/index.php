<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Monitor IoT</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
            background-color: #f0f0f0;
        }
        .card {
            background: white;
            border-radius: 8px;
            padding: 20px;
            margin: 10px 0;
            box-shadow: 0 2px 4px rgba(0,0,0,0.1);
        }
        .valor {
            font-size: 24px;
            font-weight: bold;
            color: #2196F3;
        }
        .controles {
            display: flex;
            gap: 10px;
            margin-top: 20px;
        }
        button {
            padding: 10px 20px;
            border: none;
            border-radius: 4px;
            background-color: #2196F3;
            color: white;
            cursor: pointer;
        }
        button:hover {
            background-color: #1976D2;
        }
        .atualizar {
            background-color: #4CAF50;
        }
        .atualizar:hover {
            background-color: #388E3C;
        }
    </style>
</head>
<body>
    <h1>Monitor IoT - Arduino</h1>
    
    <div class="card">
        <h2>Temperatura</h2>
        <div class="valor" id="temperatura">--°C</div>
    </div>

    <div class="card">
        <h2>Umidade</h2>
        <div class="valor" id="umidade">--%</div>
    </div>

    <div class="card">
        <h2>Luminosidade</h2>
        <div class="valor" id="luminosidade">--</div>
    </div>

    <div class="card">
        <h2>Controle do LED</h2>
        <div class="controles">
            <button onclick="controlarLED('acender')">Ligar LED</button>
            <button onclick="controlarLED('apagar')">Desligar LED</button>
        </div>
    </div>

    <button class="atualizar" onclick="atualizarDados()">Atualizar Dados</button>

    <script>
        function atualizarDados() {
            // Temperatura
            fetch('proxy.php?endpoint=temperatura')
                .then(response => response.json())
                .then(data => {
                    document.getElementById('temperatura').textContent = data.temperatura + '°C';
                })
                .catch(error => console.error('Erro:', error));

            // Umidade
            fetch('proxy.php?endpoint=umidade')
                .then(response => response.json())
                .then(data => {
                    document.getElementById('umidade').textContent = data.umidade + '%';
                })
                .catch(error => console.error('Erro:', error));

            // Luminosidade
            fetch('proxy.php?endpoint=luminosidade')
                .then(response => response.json())
                .then(data => {
                    document.getElementById('luminosidade').textContent = data.luminosidade;
                })
                .catch(error => console.error('Erro:', error));
        }

        function controlarLED(acao) {
            fetch(`proxy.php?endpoint=${acao}`)
                .then(response => {
                    console.log('LED:', acao);
                })
                .catch(error => console.error('Erro:', error));
        }

        // Atualiza os dados quando a página carrega
        atualizarDados();
        // Atualiza os dados a cada 5 segundos
        setInterval(atualizarDados, 5000);
    </script>
</body>
</html> 