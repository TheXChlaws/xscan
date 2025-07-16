
## 16. docs/TROUBLESHOOT.md

```markdown
# Troubleshooting Guide

## Common Issues

### 1. Compilation Errors
**Problem**: Errors during `make` or `cmake --build .`

**Solutions**:
- Ensure all dependencies are installed:
  ```bash
  # Linux
  sudo apt install build-essential cmake
  
  # Windows
  choco install cmake mingw
