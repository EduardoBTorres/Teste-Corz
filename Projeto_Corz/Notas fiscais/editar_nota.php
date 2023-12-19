<?php
$servername = "localhost";
$username = "mariadb";
$password = "mariadb";
$dbname = "teste_corz_eduardo";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Falha na conexão: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "GET" && isset($_GET["id"])) {
    $notaId = $_GET["id"];

    $sql = "SELECT * FROM notas_fiscais WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("i", $notaId);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows === 1) {
        $nota = $result->fetch_assoc();
    } else {
        echo "Nota fiscal não encontrada.";
    }

    $stmt->close();
}

$conn->close();
?>


