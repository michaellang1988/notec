use pyo3::{prelude::*, wrap_pymodule};

mod pulse;

/// Formats the sum of two numbers as string.
#[pyfunction]
fn version() -> PyResult<String> {
    let version = "0.0.1";
    Ok(String::from(version))
}

/// A Python module implemented in Rust.
#[pymodule]
fn rqcat(_py: Python, m: &PyModule) -> PyResult<()> {
    m.add_wrapped(wrap_pymodule!(pulse::pulse))?;
    m.add_function(wrap_pyfunction!(version, m)?)?;
    Ok(())
}
