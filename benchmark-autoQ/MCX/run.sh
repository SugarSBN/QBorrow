#!/bin/bash

echo "Verifying MCX circuits with 501 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./500/pre.hsl ./500/circuit.qasm ./500/post.hsl

echo "Verifying MCX circuits with 1001 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./1000/pre.hsl ./1000/circuit.qasm ./1000/post.hsl

echo "Verifying MCX circuits with 1501 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./1500/pre.hsl ./1500/circuit.qasm ./1500/post.hsl

echo "Verifying MCX circuits with 2001 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./2000/pre.hsl ./2000/circuit.qasm ./2000/post.hsl

echo "Verifying MCX circuits with 2501 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./2500/pre.hsl ./2500/circuit.qasm ./2500/post.hsl

echo "Verifying MCX circuits with 3001 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./3000/pre.hsl ./3000/circuit.qasm ./3000/post.hsl

echo "Verifying MCX circuits with 3501 qubits in AutoQ..."
~/AutoQ/build/cli/autoq ver ./3500/pre.hsl ./3500/circuit.qasm ./3500/post.hsl