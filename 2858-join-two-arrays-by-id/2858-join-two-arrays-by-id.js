var join = function(arr1, arr2) {
    const r = (acc, x) => ((acc[x.id] = x), acc);
    const d = arr1.reduce(r,{});
    arr2.forEach(x => (d[x.id] ? Object.assign(d[x.id], x): (d[x.id] = x))
    )
    return Object.values(d)
};