/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    return await new Promise(p=>setTimeout(p,millis));
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */