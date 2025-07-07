<?php
    $host = "localhost";
    $banco = "domotica";
    $usuario = "usuario";
    $senha = "senha";

    $conn = new mysqli($host, $usuario, $senha, $banco);

    if($conn->connect_error){
        die("Erro de conexão: " . $conn->connect_error);
    }

    return $conn;
?>