<?php
$servername = "localhost";
$username = "mariadb";
$password = "mariadb";
$dbname = "teste_corz_eduardo";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Falha na conexão: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["submit_edit"])) {
    $notaId = $_POST["nota_id"];
    $novaDataEmissao = $_POST["data_emissao"];
    $novoValorNota = $_POST["valor_nota"];

    $sql = "UPDATE notas_fiscais SET data_emissao = ?, valor_nota = ? WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("sdi", $novaDataEmissao, $novoValorNota, $notaId);
    $stmt->execute();

    if ($stmt->affected_rows > 0) {
        echo "Nota fiscal atualizada com sucesso.";

        // Redirecionamento para notas.php após a edição
        header("Location: notas.php");
        exit(); 
    } else {
        echo "Erro ao atualizar a nota fiscal.";
    }

    $stmt->close();
}

$conn->close();
?>
