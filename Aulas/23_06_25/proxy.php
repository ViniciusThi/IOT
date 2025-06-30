<?php
// Permitir CORS
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: GET');
header('Access-Control-Allow-Headers: Content-Type');
header('Content-Type: application/json');

// Função para fazer requisição ao Arduino
function fazerRequisicao($endpoint) {
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, "http://10.0.2.253/" . $endpoint);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_TIMEOUT, 5);
    $response = curl_exec($ch);
    $httpcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    curl_close($ch);

    if ($httpcode == 200) {
        return $response;
    } else {
        return json_encode(['erro' => 'Falha ao conectar com o Arduino']);
    }
}

// Pegar o endpoint da URL
$endpoint = isset($_GET['endpoint']) ? $_GET['endpoint'] : '';

// Lista de endpoints válidos
$endpointsValidos = ['temperatura', 'umidade', 'luminosidade', 'acender', 'apagar'];

// Verificar se o endpoint é válido
if (in_array($endpoint, $endpointsValidos)) {
    echo fazerRequisicao($endpoint);
} else {
    echo json_encode(['erro' => 'Endpoint inválido']);
}
?> 