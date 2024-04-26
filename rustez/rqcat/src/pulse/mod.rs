use pyo3::prelude::*;

mod base_pulse;
mod t_pulse;


#[pymodule]
pub fn pulse(_py: Python, m: &PyModule) -> PyResult<()> {
    m.add_class::<base_pulse::PulseComponent>()?;
    Ok(())
}