# P7-project

Problem:
In this project we are trying to figure out how to build a user authentication system. We're testing how to securely store passwords by using a caesar cipher combined with a random salt to encrypt them. The idea is to see if we can match encrypted passwords during login to authenticate passwords

Real-World Application:
The real-world application of your project is in user authentication systems—the kind used to secure access to websites, apps, and digital services.

Overview:
This program lets you add users with a username and password, encrypts their password using a Caesar cipher and a random salt (a number that adds extra randomness), and stores them in a hash table for quick lookup. When someone tries to log in, the program re-encrypts the entered password using the same method and compares it to the stored one to check if it matches. If it does, the user is authenticated. The program also allows you to display all the users and their encrypted information for testing.

Procedure:
The program begins by allowing users to register with a username and password. When a user is added, a random number called a "salt" is generated to make their password more secure. The password is then encrypted using a Caesar cipher, where each letter is shifted by a value based on the salt. The system calculates a hash value from the username to determine where to store the user in a hash table, which allows for faster access later. During login, the program retrieves the stored salt for the given username and uses it to encrypt the entered password again. If the re-encrypted password matches what was stored, the user is authenticated. Finally, there is a display function that lists all users by going through the entire hash table, showing each username along with their encrypted password and salt for verification or debugging purposes.

Time and Space Complexity:
Time complexity: O(1)
Space complexity: O(n)
