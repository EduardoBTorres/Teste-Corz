<?php
$servername = "localhost";
$username = "mariadb";
$password = "mariadb";
$dbname = "teste_corz_eduardo";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Falha na conexão: " . $conn->connect_error);
}

// Operação de CREATE (Inserção) para clientes
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["submit_create"])) {
    $nomeCliente = $_POST["nome_cliente"];
    $emailCliente = $_POST["email_cliente"];

    $sql = "INSERT INTO clientes (nome, email) VALUES (?, ?)";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ss", $nomeCliente, $emailCliente);

    $stmt->execute();
    $stmt->close();
}

// Operação de READ (Leitura) dos clientes
$sql = "SELECT * FROM clientes";
$result = $conn->query($sql);
$clientes = [];
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $clientes[] = $row;
    }
}

// Operação de UPDATE (Atualização) para clientes
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["submit_update"])) {
    $clienteId = $_POST["cliente_id"];
    $nomeCliente = $_POST["nome_cliente"];
    $emailCliente = $_POST["email_cliente"];

    $sql = "UPDATE clientes SET nome = ?, email = ? WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ssi", $nomeCliente, $emailCliente, $clienteId);

    $stmt->execute();
    $stmt->close();
}

// Operação de DELETE (Exclusão) para clientes
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["submit_delete"])) {
    $clienteId = $_POST["cliente_id"];

    $sql = "DELETE FROM clientes WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("i", $clienteId);

    $stmt->execute();
    $stmt->close();
}

// Operação de INSERT para nova nota fiscal
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["submit_create_nota"])) {
    $dataEmissao = $_POST["data_emissao"];
    $valorNota = $_POST["valor_nota"];

    $sql = "INSERT INTO notas_fiscais (data_emissao, valor_nota) VALUES (?, ?)";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("sd", $dataEmissao, $valorNota);

    if ($stmt->execute()) {
        echo "Nova nota fiscal inserida com sucesso!";
    } else {
        echo "Erro ao inserir a nota fiscal: " . $stmt->error;
    }

    $stmt->close();
}

$conn->close();
?>
