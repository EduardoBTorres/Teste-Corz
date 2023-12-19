CREATE TABLE clients (
	id INTEGER PRIMARY KEY,
	nome VARCHAR(20), 
	email VARCHAR(20), 
	fk_invoices_id INTEGER
	);
	
CREATE TABLE invoices (
    id INTEGER PRIMARY KEY,
    client_id INTEGER,
    emission_date DATE,
    total_value FLOAT
);

CREATE TABLE products (
    id INTEGER PRIMARY KEY,
    name VARCHAR,
    unitary_value FLOAT
);

CREATE TABLE itens (
    fk_products_id INTEGER,
    fk_invoices_id INTEGER,
    id INTEGER PRIMARY KEY,
    product_id INTEGER,
    invoice_id INTEGER,
    amount INTEGER,
    total_item_value FLOAT
);
 
ALTER TABLE clients ADD CONSTRAINT FK_clients_2
    FOREIGN KEY (fk_invoices_id)
    REFERENCES invoices (id)
    ON DELETE RESTRICT;
 
ALTER TABLE itens ADD CONSTRAINT FK_itens_2
    FOREIGN KEY (fk_products_id)
    REFERENCES products (id)
    ON DELETE RESTRICT;
 
ALTER TABLE itens ADD CONSTRAINT FK_itens_3
    FOREIGN KEY (fk_invoices_id)
    REFERENCES invoices (id)
    ON DELETE RESTRICT;