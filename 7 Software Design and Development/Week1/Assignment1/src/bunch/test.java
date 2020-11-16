package bunch;

import java.util.Scanner;

    public class test {

/*
* This program grabs a password from the user, displays the password prior to hashing and salting,
* proceeds to hash and salt, displays the password after the encryption, then asks for password verification
* and compares the new input against the encryption to see if it is similar.
*/
        public static void main(String[] args) {
            System.out.println("Enter password: ");
            Scanner scanner = new Scanner(System.in);
            String password = scanner.nextLine();
            User user =  new User(password);
            System.out.println(user);
            try {
                NSALoginController.hashUserPassword(user);
            }
            catch (Exception WeakPasswordException) {
            }
            System.out.println(user);

            System.out.println("Please re-enter password: ");
            Scanner scanner1 = new Scanner(System.in);
            String passVerify = scanner1.nextLine();
            user.setPassword(passVerify);
            try {
                boolean verified = NSALoginController.verifyPassword(user);
                if (verified == true) {
                    System.out.println("Password correct!");
                }
                else {
                    System.out.println("Password incorrect");
                }

            }
            catch (Exception WeakPasswordException) {
            }
        }
    }
