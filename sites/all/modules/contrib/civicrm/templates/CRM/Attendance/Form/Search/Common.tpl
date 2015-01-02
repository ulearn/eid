{literal} 
<script type="text/javascript" >

function checkgroup()
{

   	if(document.getElementById("group").value == '')
				{
					alert("Please select group first");
					return false;
					
				}
	return true;

}
</script>
{/literal}

<tr>
    <td >
     {$form.group.label}
    {$form.group.html}
    </td>
    <td >
      <input type="submit" value="View Partial Attendance Report" name="view_partial_attendance" onclick = "return checkgroup();"/>
    </td>
    <td >
    <input type="submit" value="View Attendance Report" name="view_attendance" onclick = "return checkgroup();" />
    </td>
   
</tr>
{* By OSSeed added field and label for date range *}
<tr>
  <td colspan="3"><label>{ts}Attendance Dates{/ts}</label></td>
</tr>
<tr> 
     {include file="CRM/Core/DateRange.tpl" fieldName="total_attendance_date" from='_low' to='_high'}
</tr> 
{* Ends by OSSeed*}
<tr> 
    <td colspan="3"> 
     {$form.member_start_date_low.label} 
     <br />
     {include file="CRM/common/jcalendar.tpl" elementName=member_start_date_low}
    </td>
</tr> 
<tr> 
    <td colspan="3">  
     {$form.member_end_date_low.label} 
     <br />
     {include file="CRM/common/jcalendar.tpl" elementName=member_end_date_low}
    </td>
   
</tr> 

{if $membershipGroupTree}
<tr>
    <td colspan="5">
    {include file="CRM/Custom/Form/Search.tpl" groupTree=$membershipGroupTree showHideLinks=false}
    </td>
</tr>
{/if}
