package bunch;

public class Cruise implements Expense {
    Destination dest;
    public Cruise(Destination choice) {
        dest = choice;
    }

    public float getCost() {
        switch (dest) {
            case Mexico:
                return (float) 1000.00;
            case Europe:
                return (float) 2000.00;
            case Japan:
                return (float) 3000.00;
            default:
                return (float) 0.00;
        }
    }
}
