-- Funcion :W para reemplazar :w  !sudo tee %
vim.api.nvim_create_user_command("W", function()
  local filepath = vim.fn.expand("%")
  local lines = vim.api.nvim_buf_get_lines(0, 0, -1, false)
  local content = table.concat(lines, "\n") .. "\n"

  local tmp = vim.fn.tempname()
  vim.fn.writefile(vim.split(content, "\n", { plain = true }), tmp)

  -- Pide la contraseña con un input de Neovim y la pasa por stdin con -S
  local password = vim.fn.inputsecret(" Sudo password: ")
  local cmd = string.format(
    "echo %s | sudo -S tee %s < %s > /dev/null",
		-- echo miPassword | sudo -S tee /etc/hosts < /tmp/nvim123 > /dev/null
    vim.fn.shellescape(password),
    vim.fn.shellescape(filepath),
    tmp
  )

  local result = vim.fn.system(cmd)
  vim.fn.delete(tmp)
  password = nil  -- limpiar de memoria lo antes posible

  if vim.v.shell_error == 0 then
    vim.bo.modified = false
    print(" Guardado: " .. filepath)
  else
    vim.notify("Error al guardar:\n" .. result, vim.log.levels.ERROR)
  end
end, {})
