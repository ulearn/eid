<div class="form-item" id="searchForm" style="display: block;">
<fieldset><legend>Search Criteria</legend>
<table class="form-layout"><tbody>

<tr>
    <td colspan="2">
     {$form.group.label}
    {$form.group.html}
    </td>
   
</tr>
<tr> 
    <td> 
     {$form.member_join_date_low.label} 
     <br />
     {include file="CRM/common/jcalendar.tpl" elementName=member_join_date_low}
    </td>
    <td> 
     {$form.member_join_date_high.label} <br />
     {include file="CRM/common/jcalendar.tpl" elementName=member_join_date_high}
    </td> 
</tr> 
<tr> 
    <td> 
     {$form.member_start_date_low.label} 
     <br />
     {include file="CRM/common/jcalendar.tpl" elementName=member_start_date_low}
    </td>
    <td>
     {$form.member_start_date_high.label}
     <br />
     {include file="CRM/common/jcalendar.tpl" elementName=member_start_date_high}
    </td> 
</tr> 
<tr> 
    <td>  
     {$form.member_end_date_low.label} 
     <br />
     {include file="CRM/common/jcalendar.tpl" elementName=member_end_date_low}
    </td>
    <td> 
     {$form.member_end_date_high.label}
     <br />
     {include file="CRM/common/jcalendar.tpl" elementName=member_end_date_high}
    </td> 
</tr> 
<tr>
  <td colspan="4">
      <input type="hidden" name="task" id="task" value="6"/>
     <input type="submit" name="Search_attendance" id="Search_attendance" value="Search"/>
  </td>
</tr>
{if $membershipGroupTree}
<tr>
    <td colspan="4">
    {include file="CRM/Custom/Form/Search.tpl" groupTree=$membershipGroupTree showHideLinks=false}
    </td>
</tr>
{/if}
</tbody>
</table>
 </fieldset>
 </div>
