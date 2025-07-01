<?php    
    require_once 'conexao.php';

    $temperatura = isset($_GET['temperatura']) ? floatval($_GET['temperatura']) : null;
    $umidade = isset($_GET['umidade']) ? floatval($_GET['umidade']) : null;
    $luminosidade = isset($_GET['luminosidade']) ? intval($_GET['luminosidade']) : null;

    if($temperatura !== null && $umidade !== null && $luminosidade !== null){

        $stmt = $conn->prepare("INSERT INTO sensores (temperatura, umidade, luminosidade) VALUES (?, ?, ?)");

        $stmt->bind_param("ddi", $temperatura, $umidade, $luminosidade);

        if($stmt->execute()){
            echo "Dados registrados com sucesso!";
        } else {
            echo "Erro ao registrar dados: " . $stmt->error;
        }
        $stmt->close();
    } else {
        echo "Por favor, forneça todos os valores necessários.";
    }
    $conn->close();
?>