package pe.antana.SistemaRiego.Controller;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import pe.antana.SistemaRiego.Beans.Entidad.HistorialSensor;
import pe.antana.SistemaRiego.Service.HistorialService;

import java.util.List;

@CrossOrigin(origins = "*", allowedHeaders = "*")
@RestController
@RequestMapping("/HistorialSensor")
public class HistorialController {
    private final HistorialService historialService;
    @Autowired
    public HistorialController(HistorialService citaService) {
        this.historialService = citaService;
    }
    @RequestMapping(value = "/Listar", method = RequestMethod.GET)
    public ResponseEntity<Object> Listar() {
        List<HistorialSensor> historial = historialService.listar();
        return new ResponseEntity<Object>(historial, HttpStatus.OK);
    }

    @RequestMapping(value = "/Insertar", method = RequestMethod.POST)
    public @ResponseBody
    ResponseEntity<Object> Insertar(@RequestBody HistorialSensor historial) {
        int insertar = historialService.insertar(historial);
        return new ResponseEntity<Object>(insertar, HttpStatus.OK);
    }
}
