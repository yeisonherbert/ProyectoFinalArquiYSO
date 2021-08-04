/*
Autor: Yeison Herbert Churquipa Yanqui
yeison.churquipa.y@uni.pe
 */
package pe.antana.SistemaRiego.Mapper;

import org.apache.ibatis.annotations.*;
import org.springframework.stereotype.Repository;
import pe.antana.SistemaRiego.Beans.Entidad.HistorialSensor;

import java.util.Date;
import java.util.List;

@Repository
@Mapper
public interface HistorialMapper {
//    @Select("SELECT idCita, idPaciente, idPersonal, fechaHoraInicio, fechaHoraFin, detalle, fechaRegistro, eliminado from Cita WHERE eliminado = FALSE and idCita = #{idCita}")
//    HistorialSensor elemento(@Param("idCita") int idCita);

    @Select("select id, sensor, ubicacion, valor, creacion from HistorialSensor")
    List<HistorialSensor> listar();


    @Insert("insert into HistorialSensor(sensor,ubicacion,valor) value (#{sensor},#{ubicacion},#{valor})")
    int Insertar(String sensor, String ubicacion, double valor);

//    @Update("UPDATE Cita SET idPaciente = #{idPaciente}, idPersonal = #{idPersonal}, fechaHoraInicio = #{fechaHoraInicio}, fechaHoraFin = #{fechaHoraFin}," +
//            " detalle = #{detalle}\n" +
//            "WHERE idCita = #{idCita}")
//    int Actualizar(int idPaciente, int idPersonal, Date fechaHoraInicio, Date fechaHoraFin, String detalle, int idCita);
//
//    @Update("UPDATE Cita SET eliminado = true WHERE idCita = #{idCita}")
//    int Eliminar(int idCita);

}
