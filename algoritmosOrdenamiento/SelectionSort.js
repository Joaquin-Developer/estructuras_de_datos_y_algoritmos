function selectionSort(arr) {

    for (let i = arr.length - 1; i >= 1; i--) {
        let mayor = max(arr, i);
        let aux = arr[mayor];
        arr[mayor] = arr[i];
        arr[i] = aux;
    }
}

/**
 * Funcion auxiliar 
 * Retornar el indice del elemento mayor
 */
function max(arreglo, indiceSuperior) {
    let indiceMayor = 0;

    for (let i = 0; i <= indiceSuperior; i++)
        if (arreglo[i] > arreglo[indiceMayor]) indiceMayor = i;

    return indiceMayor;
}

// para imprimir el array un poquito mas lindo ^-^
function printArray(arr) {
    console.log(
        arr.toString().replaceAll(",", " - ")
    )
}

let arr = [3, 42, 4, 1, 21, 20, 5, 10];
printArray(arr)

selectionSort(arr);

printArray(arr)