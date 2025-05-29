Array.prototype.groupBy = function(fn) {
    return this.reduce((res, item) => {
        const key = fn(item);
        (res[key] ||= []).push(item);
        return res;
    }, {});
};