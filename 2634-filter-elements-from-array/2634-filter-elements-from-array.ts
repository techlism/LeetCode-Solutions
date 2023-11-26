type Fn = (n: number, i: number) => any

function filter(arr: number[], fn: Fn): number[] {
	let data = []

    arr.map((item, index) => {
        if (fn(item, index)) {
            data.push(item)
        }
    })
    return data;
};