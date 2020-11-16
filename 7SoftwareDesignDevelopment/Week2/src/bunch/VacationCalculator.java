package bunch;

import java.util.List;
import java.util.ArrayList;

/**
 * This class is used to calculate the cost of a vacation based on where we're going,
 * how long we'll be there, and what we're planning to do.
 * <p>
 * @author  Brother Falin
 * @version 1.0
 * @since   2016-12-08
 */
public class VacationCalculator {

    /**
     * This is the main method we use for testing the vacation code.
     * @param args Unused.
     */
    public static void main(String[] args) {

        // Create an instance of the VacationCalculator class so we
        // can access its methods
        VacationCalculator vc = new VacationCalculator();

        float japanCost = vc.calculateVacationCost(Destination.Japan, 5);
        float mexicoCost = vc.calculateVacationCost(Destination.Mexico, 3);
        float europeCost = vc.calculateVacationCost(Destination.Europe, 7);

        // Note the use of System.out.format here, instead of println
        // This allows us to use format specifiers, but requires us to insert the
        // new-line (%n) ourselves.
        // For details, see:
        // https://docs.oracle.com/javase/tutorial/essential/io/formatting.html
        System.out.format(String.format("Total cost for trip to Japan:  $%.2f%n", japanCost));
        System.out.format(String.format("Total cost for trip to Mexico: $%.2f%n", mexicoCost));
        System.out.format(String.format("Total cost for trip to Europe: $%.2f%n", europeCost));
    }

    /**
     * This is the main method we use for testing the vacation code.
     * @param dest Where we're going on vacation.
     * @param totalNights How long we're staying there.
     * @return The total cost of the vacation.
     */
    public float calculateVacationCost(Destination dest, int totalNights) {

        // Build the itenerary. Note that we insantiate an ArrayList, but
        // store it as a List. This is another example of "programming
        // to an interface."
        //
        // For a list of classes that implement the List interface,
        // see the "All Known Implementing Classes" section of:
        // http://docs.oracle.com/javase/8/docs/api/java/util/List.html
        List<Expense> itenerary = new ArrayList<Expense>();
        itenerary.add(new Cruise(dest));
        itenerary.add(new Dining(dest, totalNights));
        itenerary.add(new Lodging(dest, totalNights));

        float totalCost = tallyExpenses(itenerary);
        return totalCost;
    }

    // The tallyExpenses() function has no idea what kind of expenses these
    // are, or how they are related. All it cares about is that they
    // all implement the expenses interface, which means they are guaranteed
    // to have a getCost() function.
    private float tallyExpenses(List<Expense> expenses) {
        float totalCost = 0;

        // This is called a "for each" loop. It is used to iterate through
        // everything in an array, in this case the List 'expenses'
        for(Expense e : expenses) {
            totalCost += e.getCost();
        }

        return totalCost;
    }
}
