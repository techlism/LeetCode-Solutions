SELECT unique_id,name
FROM EmployeeUNI eu
RIGHT JOIN Employees e
ON eu.id=e.id;