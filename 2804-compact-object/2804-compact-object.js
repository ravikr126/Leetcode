/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        // If the input is an array, recursively compact each element
        return obj
            .map(compactObject) // Recursively process elements
            .filter(Boolean);   // Remove falsy values
    } else if (typeof obj === "object" && obj !== null) {
        // If the input is an object, recursively compact each property
        const result = {};
        for (const key in obj) {
            const value = compactObject(obj[key]); // Recursively process values
            if (Boolean(value)) {                 // Add only truthy values
                result[key] = value;
            }
        }
        return result;
    }
    // For primitive values, return as-is
    return obj;
};