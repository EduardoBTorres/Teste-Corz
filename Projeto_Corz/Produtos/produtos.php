<?php
$servername = "localhost";
$username = "mariadb";
$password = "mariadb";
$dbname = "teste_corz_eduardo";  

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Falha na conexão: " . $conn->connect_error);
}

// Operação de CREATE (Inserção)
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["submit_create"])) {
    $nomeProduto = $_POST["nome_produto"];
    $valorUnitario = $_POST["valor_unitario"];

    $sql = "INSERT INTO produtos (name, unitary_value) VALUES (?, ?)";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("sd", $nomeProduto, $valorUnitario);

    $stmt->execute();
    $stmt->close();
}

// Operação de READ (Leitura)
$sql = "SELECT * FROM productos";
$result = $conn->query($sql);
$produtos = [];
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $produtos[] = $row;
    }
}

// Operação de UPDATE (Atualização)
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["submit_update"])) {
    $produtoId = $_POST["produto_id"];
    $nomeProduto = $_POST["nome_produto"];
    $valorUnitario = $_POST["valor_unitario"];

    $sql = "UPDATE produtos SET name = ?, unitary_value = ? WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("sdi", $nomeProduto, $valorUnitario, $produtoId);

    $stmt->execute();
    $stmt->close();
}

// Operação de DELETE (Exclusão)
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["submit_delete"])) {
    $produtoId = $_POST["produto_id"];

    $sql = "DELETE FROM produtos WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("i", $produtoId);

    $stmt->execute();
    $stmt->close();
}

$conn->close();
?>
