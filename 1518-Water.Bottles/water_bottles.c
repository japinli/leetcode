/*----------------------------------------------------------------------------
 *
 * water_bottles.c
 *   Given `numBottles` full water bottles, you can exchange `numExchange`
 *   empty water bottles for one full water bottle.
 *
 *   The operation of drinking a full water bottle turns it into an empty bottle.
 *
 *   Return the maximum number of water bottles you can drink.
 *
 *----------------------------------------------------------------------------
 */

int
numWaterBottles(int numBottles, int numExchange)
{
    int drink = numBottles;

    while (numBottles >= numExchange) {
        drink += numBottles / numExchange;
        numBottles = numBottles % numExchange + numBottles / numExchange;
    }

    return drink;
}
