const insertionSort = array => { 
    
    for (let i = 1; i <= array.length; i++) { 
        let j = i
    
        while (j >= 1 && array[j] < array[j - 1]) { 
            // Intercambiar array[j] por array[j - 1] 
            let aux = array[j]
            array[j] = array[j - 1]
            array[j - 1] = aux
            j--;
        } 
    } 
}