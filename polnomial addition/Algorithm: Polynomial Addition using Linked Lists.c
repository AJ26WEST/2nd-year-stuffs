1. Structure Definition:
Define a Term structure with three fields:
coefficient (integer): Coefficient of the polynomial term.
exponent (integer): Exponent of the polynomial term.
next (pointer): Points to the next term in the linked list.


  
2. Polynomial Insertion Algorithm:
Input: Coefficient and exponent of a term, and the linked list representing the polynomial.

Output: A new polynomial linked list with the term added.

insertTerm(Polynomial, coefficient, exponent):
    Step 1: Create a new node using the given coefficient and exponent.
    Step 2: If Polynomial is NULL:
               Set Polynomial to point to the new node.
               Return Polynomial.
    Step 3: Otherwise, traverse to the end of the linked list.
    Step 4: Insert the new node at the end of the list.
    Step 5: Return Polynomial.

  3. Algorithm to Add Two Polynomials:
Input: Two polynomial linked lists P1 and P2.

Output: A new linked list P3 representing the sum of P1 and P2.

  addPolynomials(P1, P2):
    Step 1: Initialize P3 to NULL.
    Step 2: Set two pointers: temp1 = P1, temp2 = P2.
    
    Step 3: While temp1 is not NULL and temp2 is not NULL:
              a. If exponent of temp1 > exponent of temp2:
                   Insert term from temp1 (coefficient, exponent) into P3.
                   Move temp1 to the next term.
              
              b. Else If exponent of temp1 < exponent of temp2:
                   Insert term from temp2 (coefficient, exponent) into P3.
                   Move temp2 to the next term.
              
              c. Else If exponents are equal:
                   Add coefficients of temp1 and temp2.
                   If the sum of coefficients is not zero:
                      Insert the sum (sum of coefficients, common exponent) into P3.
                   Move both temp1 and temp2 to the next term.
    
    Step 4: While temp1 is not NULL:
              Insert the remaining terms from temp1 into P3.
              Move temp1 to the next term.
    
    Step 5: While temp2 is not NULL:
              Insert the remaining terms from temp2 into P3.
              Move temp2 to the next term.

    Step 6: Return P3.


  4. Algorithm to Display Polynomial:
Input: A polynomial linked list.

Output: Prints the polynomial in standard mathematical format.

  displayPolynomial(Polynomial):
    Step 1: Set temp = Polynomial.
    Step 2: While temp is not NULL:
              Print coefficient and exponent in the form "coefficient x^exponent".
              If temp->next is not NULL and the next coefficient is non-negative:
                   Print " + " (to show positive terms).
              Move temp to the next term.
    Step 3: End.
STEP- STOP
