SELECT product_name,year,price
FROM Product pd
INNER JOIN Sales s
ON pd.product_id = s.product_id;
