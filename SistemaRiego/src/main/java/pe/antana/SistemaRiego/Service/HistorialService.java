package pe.antana.SistemaRiego.Service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import pe.antana.SistemaRiego.Beans.Entidad.HistorialSensor;
import pe.antana.SistemaRiego.Mapper.HistorialMapper;

import java.util.List;

@Service
public class HistorialService {
    private final HistorialMapper citaMapper;

    @Autowired
    public HistorialService(HistorialMapper citaMapper) {
        this.citaMapper = citaMapper;
    }

//    public HistorialSensor elemento(int IdCita) {
//        return citaMapper.elemento(IdCita);
//    }

    public List<HistorialSensor> listar() {
        return citaMapper.listar();
    }

//    public List<CitaConDetalle> listarConDetalle() {
//        return citaMapper.listarConDetalle();
//    }

    public int insertar(HistorialSensor sensor) {
        return citaMapper.Insertar(
                sensor.getSensor(),
                sensor.getUbicacion(),
                sensor.getValor()
        );
    }


//    public int actualizar(Cita cita) {
//        return citaMapper.Actualizar(
//                cita.getIdPaciente(),
//                cita.getIdPersonal(),
//                cita.getFechaHoraInicio(),
//                cita.getFechaHoraFin(),
//                cita.getDetalle(),
//                cita.getIdCita()
//        );
//    }

//    public int eliminar(int IdCita) {
//        return citaMapper.Eliminar(IdCita);
//
//    }
}
