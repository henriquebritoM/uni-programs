mod quick_sort;
use quick_sort::QuickSortable;

fn main() {

    test(1_000_000, "1 milhão de músicas");
    test(2_000_000, "2 milhões de músicas");
    test(3_000_000, "3 milhões de músicas");

    /* Quando compilado sem compiler optimizations:                 */
    /* Modo pro e naive demoram ~15s segundos                       */
    /* Pode exceder o tempo de execução do rust playground          */
    // test(10_000_000, "10 milhões de músicas");

    /* Quando compilado sem compiler optimizations                  */
    /* Modo pro e naive demoram ~3 minutos cada                     */
    // test(100_000_000, "100 milhões de músicas"); 
    
    /* 
     * Nos testes com arrays preenchidos aleatóriamente não há muita diferença,
     * na verdade, o modo naive está ganhando nos testes. (Não sei o motivo)
     * Porém, quando testado no pior caso do quick sort (array já ordenado), 
     * o modo naive não consegue ordenar vetores com mais de 100 000 elementos 
     * antes de estourar no tempo
    */

    println!("\n\n");

    test_com_vetor_ordenado(1_000, "Vetor ordenado: 1 000 elementos");
    test_com_vetor_ordenado(10_000, "Vetor ordenado: 10 000 elementos");
    test_com_vetor_ordenado(20_000, "Vetor ordenado: 20 000 elementos");
    //  O modo naive é tão lento que não tive paciência de marcar o tempo
    // test_com_vetor_ordenado(100_000, "Vetor ordenado: 100 000 elementos");
}

fn preenche_vetor(n: usize) -> Vec<u32>{

    let mut vec: Vec<u32> = Vec::with_capacity(n);

    let (min, max) = (1_000, 10_000_000);

    for _ in 0..vec.capacity() {
        vec.push(rand::random_range(min..max));
    }

    return vec;
}

fn test_sort(vec: &mut Vec<u32>, test_name: &str) {

    let mut vec2 = vec.clone();
    let mut vec3 = vec.clone();

    let mut instant;
    let mut elapsed;
    
    println!("========================================");
    println!("Test {}", test_name);

    instant = std::time::Instant::now();
    vec.as_mut_slice().qsort();
    elapsed = instant.elapsed();
    
    assert!(vec.is_sorted());
    println!("Modo pro: {} milisegundos", elapsed.as_millis());
    
    instant = std::time::Instant::now();
    vec2.as_mut_slice().qsort_naive();
    elapsed =instant.elapsed();

    assert!(vec2.is_sorted());
    println!("Modo naive: {} milisegundos", elapsed.as_millis());

    instant = std::time::Instant::now();
    vec3.as_mut_slice().sort();
    elapsed =instant.elapsed();

    assert!(vec3.is_sorted());
    println!("Sort padrão rust: {} milisegundos", elapsed.as_millis());
}

fn test(n: usize, test_name: &str) {

    //  Cria dois vetores iguais
    let mut vec: Vec<u32> = preenche_vetor(n);

    test_sort(&mut vec, test_name);
}

fn preenche_vetor_ordenadamente(n: usize) -> Vec<u32>{

    let mut vec: Vec<u32> = Vec::with_capacity(n);

    for i in 0..vec.capacity() {
        vec.push(i.try_into().unwrap()); 
    }

    return vec;
}

fn test_com_vetor_ordenado(n: usize, test_name: &str) {
    let mut vec: Vec<u32> = preenche_vetor_ordenadamente(n);

    test_sort(&mut vec, test_name);
}

