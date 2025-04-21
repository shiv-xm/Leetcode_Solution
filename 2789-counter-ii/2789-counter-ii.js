/**
 * @param {number} init
 * @return {{ increment: Function, decrement: Function, reset: Function }}
 */
var createCounter = function(init) {
    let current = init;

    return {
        increment: () => {
            current += 1;
            return current;
        },
        decrement: () => {
            current -= 1;
            return current;
        },
        reset: () => {
            current = init;
            return current;
        }
    };
};

/**
 * Example usage:
 * const counter = createCounter(5);
 * console.log(counter.increment()); // 6
 * console.log(counter.reset());     // 5
 * console.log(counter.decrement()); // 4
 */
