mod counting_sort;
use counting_sort::CountingSortable;

fn main() {

    test(1_000_000, 100);
    test(1_000_000, 10_000);
    test(1_000_000, 100_000);

    println!("");
    
    test(2_000_000, 100);
    test(2_000_000, 10_000);
    test(2_000_000, 100_000);

    println!("");

    test(3_000_000, 100);
    test(4_000_000, 10_000);
    test(5_000_000, 100_000);

    println!("");

}

fn preenche_vetor(n: usize, k: usize) -> Vec<u32>{

    let mut vec: Vec<u32> = Vec::with_capacity(n);

    let k: u32 = k.try_into().unwrap();

    let (min, max) = (0, k.try_into().unwrap());

    vec.push(k - 1);    //  Garantir que vamos ter o K máximo sempre
    for _ in 1..vec.capacity() {
        vec.push(rand::random_range(min..max));
    }

    return vec;
}

fn test_sort(vec: &mut Vec<u32>, test_name: String) {

    let mut vec2 = vec.clone();

    let mut instant;
    let mut elapsed;
    
    println!("========================================");
    println!("Test {}", test_name);

    instant = std::time::Instant::now();
    vec.as_mut_slice().counting_sort();
    elapsed = instant.elapsed();
    
    assert!(vec.is_sorted());
    println!("Merge sort: {} milisegundos", elapsed.as_millis());

    instant = std::time::Instant::now();
    vec2.as_mut_slice().sort();
    elapsed =instant.elapsed();

    assert!(vec2.is_sorted());
    println!("Sort padrão rust: {} milisegundos", elapsed.as_millis());
}

fn test(n: usize, k: usize) {

    let mut vec: Vec<u32> = preenche_vetor(n, k);
    let test_name = format!("Counting Sort: n = {}, k = {}", n, k);

    test_sort(&mut vec, test_name);
}