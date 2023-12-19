<?php
$servername = "localhost";
$username = "mariadb";
$password = "mariadb";
$dbname = "teste_corz_eduardo";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Falha na conexão: " . $conn->connect_error);
}

// Operação de DELETE (Exclusão) de notas fiscais
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["submit_delete"])) {
    $notaId = $_POST["nota_id"];

    $sql = "DELETE FROM notas_fiscais WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("i", $notaId);

    $stmt->execute();
    $stmt->close();
}

// Operação de READ (Leitura) das notas fiscais
$sql = "SELECT * FROM notas_fiscais";
$result = $conn->query($sql);
$notasFiscais = [];
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $notasFiscais[] = $row;
    }
}

$conn->close();
?>

