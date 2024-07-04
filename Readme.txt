1. All inputs are taken in the form of strings. So any input after a whitespace(space,tab,e.t.c) is ignored.
2. We do not assign a username and password to the manager since there is only One manager.
3. Manager can add a car-
             condition entered can only be "good" , "mid" , "bad".
             price entered can only be a positive integer.
4. Manager can delete a car by entering the car's id(can view all car ids by entering view option) -
             if car is not rented to some user(employee/customer).
5. Manager can update a car by entering the car's id (can view all car ids by entering view option) -
             1) Model any string input assumed valid.
             2) condition entered can only be "good" , "mid" , "bad".
             3)  price entered can only be a positive integer.
6. Manager can search a car by entering the car's id (can view all car ids by entering view option) -
                            - In order to find out who this car is rented, Manager needs to search for the corresponding user using the                        id.
7. Manager view all cars and their respective information.
8. Manager can add an employee/customer .
           - new user should not have a matching id, or (name and password) with another user of same class;
9. Manager can delete an employee/customer using their id.
            - if user has cleared all dues and does not have any rented cars.
10.Manager can update an employee/customer using their id.
            - cannot have two users with same id.
            - cannot have two users with same names and password.
11. Manager can search for an employee/customer using their id.
12. Manager can view all employees/customers(includes id, password, current dues, cars rented,record).
13. Employees/Customers need to login with their username and password.
14. Employees/Customers can view available cars and all cars and rented cars.
15. Employees/Customers can rent a car.
                    - if they are below their respective rent limit.
                    - if no other user currently rents that car.
                    - while renting they are expected to enter the correct car id and the correct current date(in dd/mm/yy format) on which they are renting.
                    - After successfully renting, the rent-price of the car will be added to their dues.
16. Employees/Customers can return a car.
                     - if they are currently renting the car.
                     - while returning the car the user is expected to enter correct car id and the correct date(dd/mm/yy format) on which they are returning the car.
                     - After successfully returning the car, fine due to late return is added to their dues.
                     - Note that untill user has returned the car fine is not imposed on him.her.
17. Employees/Current can clear their current dues(partially/ wholly).
                     - While clearing their dues they are expected to enter a postive integer less than current dues.
18. Employees/Customers can view their own details(includes id, password, current dues, cars rented,record).
19. Late-fine per day = $1
    User record decreases by 1 per $20 late fine.
    User record cannot be less than 1 and more than 10.
    If user has record-
              less than 4 - can rent max 1 car
              less than 7 - can rent max 2 cars
              less than 10 - can rent max 3 car
              equal to 10  - can rent max 4 cars
20. Employees have user-names emp1, emp2, emp3, emp4, emp5 ; Passwords 123.
21. Customers have user-names cust1, cust2, cust3, cust4, cust5 ; Passwords 123.
