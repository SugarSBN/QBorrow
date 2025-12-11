#!/bin/bash

echo "Verifying adder circuits with 99 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./50/pre.hsl ./50/circuit.qasm ./50/post.hsl

echo "Verifying adder circuits with 149 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./75/pre.hsl ./75/circuit.qasm ./75/post.hsl

echo "Verifying adder circuits with 199 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./100/pre.hsl ./100/circuit.qasm ./100/post.hsl

echo "Verifying adder circuits with 249 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./125/pre.hsl ./125/circuit.qasm ./125/post.hsl

echo "Verifying adder circuits with 299 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./150/pre.hsl ./150/circuit.qasm ./150/post.hsl

echo "Verifying adder circuits with 349 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./175/pre.hsl ./175/circuit.qasm ./175/post.hsl

echo "Verifying adder circuits with 399 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./200/pre.hsl ./200/circuit.qasm ./200/post.hsl