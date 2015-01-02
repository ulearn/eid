 <table class="selector" summary="Search results listings." style="position: relative;">
  <thead class="sticky">
    <tr>
      <th scope="col">Name</th>
      <th scope="col">Total class days</th>
      <th scope="col">Total attended days</th>
      <th scope="col">Percentage</th>
    </tr>
  </thead>
  <tbody>
  {assign var=partialcount value=0}
  {foreach from=$associatedAttendance item=dataitem}
                  <tr class="{cycle values="odd-row,even-row"}">
                  <span style="display:none">{$partialcount++}</span>
                    <td title="Name" scope="col">
                        <a href="/civicrm/contact/view?reset=1&amp;cid={$dataitem.contact_id}">{$dataitem.sort_name} </a> 
                    </td>
                     <td title="Total class days" scope="col">
                        {$dataitem.total_class_days}    
                    </td>
                     <td title="Total attended days" scope="col">
                        {$dataitem.total_attended_days}    
                    </td>
                     <td title="Percentage" scope="col">
                        {$dataitem.persentage}    
                    </td>
                  </tr>
    {/foreach}  
    </tbody>
  </table>
   