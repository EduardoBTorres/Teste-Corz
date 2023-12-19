<?php
// Conexão com o banco de dados
$servername = "localhost";
$username = "mariadb";
$password = "mariadb";
$dbname = "teste_corz_eduardo";

$conn = new mysqli($servername, $username, $password, $dbname);

// Verifica a conexão
if ($conn->connect_error) {
    die("Falha na conexão: " . $conn->connect_error);
}

// Função para listar todos os clientes
function listarClientes($conn) {
    $sql = "SELECT * FROM clientes";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo "ID: " . $row["id"] . " - Nome: " . $row["nome"] . " - Email: " . $row["email"] . "<br>";
        }
    } else {
        echo "Nenhum cliente encontrado.";
    }
}

// Exemplo de chamada para listar clientes
listarClientes($conn);

// Fecha a conexão
$conn->close();
?>