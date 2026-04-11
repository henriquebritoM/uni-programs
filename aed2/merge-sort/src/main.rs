use crate::merge_sort::MergeSortable;

mod merge_sort;

fn main() {

    test(1_000_000, "1 milhão de registros");
    test(2_000_000, "2 milhões de registros");
    test(3_000_000, "3 milhões de registros");

    /* Quando compilado sem compiler optimizations:                     */
    /* Merge e o sort padrão demoram ~9-10 segundos                     */
    // test(10_000_000, "10 milhões de registros");

    /* Quando compilado sem compiler optimizations                      */
    /* Merge e o sort padrão demoram ~100 segundos cada                 */
    // test(100_000_000, "100 milhões de registros"); 

    /* Quando usadas otimizações do compilador, o sort padrão fica      */
    /* Muito mais rápido do que o meu merge sort                        */

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

    let mut instant;
    let mut elapsed;
    
    println!("========================================");
    println!("Test {}", test_name);

    instant = std::time::Instant::now();
    vec.as_mut_slice().merge_sort();
    elapsed = instant.elapsed();
    
    assert!(vec.is_sorted());
    println!("Merge sort: {} milisegundos", elapsed.as_millis());

    instant = std::time::Instant::now();
    vec2.as_mut_slice().sort();
    elapsed =instant.elapsed();

    assert!(vec2.is_sorted());
    println!("Sort padrão rust: {} milisegundos", elapsed.as_millis());
}

fn test(n: usize, test_name: &str) {

    let mut vec: Vec<u32> = preenche_vetor(n);

    test_sort(&mut vec, test_name);
}